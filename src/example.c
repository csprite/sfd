#include "sfd.h"
#include <stdio.h>

int main(void) {
	sfd_Options opt = {
		.title        = "Open Image File",
		.filter_name  = "Image File",
		.filter       = "*.png|*.jpg",
		.save         = 0
	};

	const char* filename = sfd_open_dialog(&opt);

	if (filename) {
		printf("Got file: '%s'\n", filename);
	} else {
		printf("Open canceled\n");
	}
	return 0;
}
