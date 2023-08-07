asm("push $0x31\n push $0x30\n push $0x80e42f6\n mov $0x8051060, %eax\n call *%eax\n movl $0x8049ec2, %ebx\n jmp *%ebx\n");
