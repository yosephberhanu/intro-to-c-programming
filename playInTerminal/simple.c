#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define CHANNEL_NUM 3
#define W 1280
#define H 720
#define IMAGE 0
#define VIDEO 1

int SCN_LINES;
int SCN_COLS;
int res;
int asciify(int pixel, int charRange)
{
	char map_large[] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
	char map_small[] = "@%#*+=-:. ";

	return (charRange == 1) ? map_small[(int)((pixel / 255.0) * 10)] : map_large[(int)((pixel / 255.0) * 70)];
}

void printImage(uint8_t *rgb_image, int width, int height, int charRange)
{
	res = height / SCN_LINES;
	for (int i = 0; i < height; i += res)
	{
		for (int j = 0; j < width; j += res)
		{
			printf("%c", asciify(*((rgb_image + (i * width) + j)), charRange));
		}
		printf("\n");
	}
}
void displayImage(char *file, int charRange)
{

	int width, height, bpp;
	uint8_t *rgb_image = stbi_load(file, &width, &height, &bpp, 1);
	printImage(rgb_image, width, height, charRange);
	stbi_image_free(rgb_image);
}
void playVideo(char *file, long fps, int charRange)
{
	int count;
	uint8_t frame[H][W][3] = {0};
	uint8_t gray[H][W] = {0};
	struct timespec tim;
	tim.tv_sec = 0;
	tim.tv_nsec = 1000000000L / fps;

	system("clear");
	char arg[255];
	strcat(arg, "ffmpeg -i ");
	strcat(arg, file);
	strcat(arg, " -f image2pipe -vcodec rawvideo -pix_fmt rgb24 -");
	FILE *pipein = popen(arg, "r");

	// Process video frames
	while ((count = fread(frame, 1, H * W * 3, pipein)) > 0)
	{
		// Read a frame from the input pipe into the buffer

		for (int y = 0; y < H; ++y)
			for (int x = 0; x < W; ++x)
			{
				gray[y][x] = (frame[y][x][0] + frame[y][x][1] + frame[y][x][2]) / 3;
			}
		printImage((uint8_t *)&gray, W, H, charRange);
		nanosleep(&tim, NULL);
		system("clear");
	}

	// Flush and close input and output pipes
	fflush(pipein);
	pclose(pipein);
}
int getFileType(char *file)
{
	/// TODO: check file type
	// return VIDEO;
	return IMAGE;
}

int main(int argc, char const *argv[])
{

	struct winsize w;
	ioctl(0, TIOCGWINSZ, &w);
	SCN_LINES = w.ws_row;
	SCN_COLS = w.ws_col;
	// char* file = "video.mp4";
	char *file = "image.jpg";
	int fps = 24;
	int charRange = 1;
	switch (getFileType(file))
	{
	case IMAGE:
		displayImage(file, charRange);
		break;
	case VIDEO:
		playVideo(file, fps, charRange);
		break;
	}
	return 0;
}
