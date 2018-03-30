#include <stdio.h>
#include <kernel/tty.h>

/*=======================================================
 * Kernel main method. This method will be active
 * after the boot loader gives control to our os (kernel)
=======================================================*/
void kernel_main(void){
  terminal_initialize();
  printf("Hello, kernel world!\n");
}
