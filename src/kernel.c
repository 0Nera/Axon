//extern void asm_hlt();

#define COLS 80
#define ROWS 25
#define SCREEN_SIZE 2000

unsigned int* vga_buffer = (unsigned int*)0xB8000;

int col = 0;
int row = 0;


void putchar(char c){
    int index = (COLS * ROWS) + ++col; // Like before, calculate the buffer index
	vga_buffer[index] = ((unsigned int)2 << 8) | 'c';
}


void kernel() {
    for (int i = 0; i < 32; i++) {
        putchar('c');
    }
    
    while(1){
        asm("hlt");
        //asm_hlt();
    }
}