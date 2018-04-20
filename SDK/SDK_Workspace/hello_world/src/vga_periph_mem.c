/*****************************************************************************
* Filename:          D:\work\lprs2\2013_2014\Resene_vezbe\lab56\basic_system/drivers/vga_periph_mem_v1_00_a/src/vga_periph_mem.c
* Version:           1.00.a
* Description:       vga_periph_mem Driver Source File
* Date:              Wed Mar 05 10:25:21 2014 (by Create and Import Peripheral Wizard)
*****************************************************************************/


/***************************** Include Files *******************************/

#include "vga_periph_mem.h"
Xuint32 cursor_position;
/************************** Function Definitions ***************************/

void set_cursor(Xuint32 new_value){
	cursor_position = new_value;
}

void clear_text_screen(Xuint32 BaseAddress){
	int i;
	for (i = 0; i < 4800; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + i*4, 0x20);
	}
}

void print_string(Xuint32 BaseAddress, unsigned char string_s[], int lenght){
	int i;
	for (i = 0; i < lenght; i++){
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position + i*4, (string_s[i]-0x40));
	}
}

void clear_graphics_screen(Xuint32 BaseAddress){
	int i;
	for (i = 0; i < 9600; i++){
	    VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
	}
}

void draw_square(Xuint32 BaseAddress){
	int i, j, k;
	for (j = 0; j < 480; j++){
		for (k = 0; k<(640/32); k++){
			i = j*(640/32) + k;
			if ((j > 200) && (j < 280) && (k > 8) && (k < 12)) {
				VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0xFFFFFFFF);
			}
			else{
				VGA_PERIPH_MEM_mWriteMemory(BaseAddress + GRAPHICS_MEM_OFF + i*4, 0x0);
			}
		}
	}
}

void print_char (Xuint32 BaseAddress, char c) {
	VGA_PERIPH_MEM_mWriteMemory(BaseAddress + TEXT_MEM_OFF + cursor_position, c-0x40);
}

void set_background_color(Xuint32 BaseAddress, int color) {
	int i;
	for (i=0; i<9600; i++) {
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + 0x14, color);
	}
}

void set_foreground_color(Xuint32 BaseAddress, int color) {
	int i;
	for (i=0; i<9600; i++) {
		VGA_PERIPH_MEM_mWriteMemory(BaseAddress + 0x10, color);
	}
}

void print_rectangle(Xuint32 BaseAddress) {

}

void move_char(Xuint32 BaseAddress) {
	int i;
	int j;
	int k = 1;

	for (i=161; i<9600; i=i+k) {
		if (i==319) k = -1;

		if(i == 161) k = 1;
			set_cursor(i);
			print_char(BaseAddress, 'A');
			for (j=0; j<100000; j++) { }
			clear_text_screen(BaseAddress);
	}
}




