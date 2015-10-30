 #include <linux/module.h>    
 #include <linux/proc_fs.h>    
 #include <linux/sched.h>
 #include <asm/uaccess.h>
 #include <asm/desc.h>
 #include <asm/pgtable.h>
 #include <asm/desc.h>
 #include <asm/system.h>

 static char modname[] = "sys_reg";
 struct gdtr_struct{
	short limit;
	unsigned long address __attribute__((packed));
  };

 static unsigned int cr0,cr3,cr4;
 static struct gdtr_struct gdtr;

 static int my_get_info( char *buf, char **start, off_t off, int count )
 {
	int	len = 0;
	struct mm_struct *mm;

	mm = current->active_mm;
	cr0 = read_cr0();
        cr3 = read_cr3();
	cr4 = read_cr4();
	asm(" sgdt gdtr");


	len += sprintf( buf+len, "cr4=%08X  ", cr4 );
	len += sprintf( buf+len, "PSE=%X  ", (cr4>>4)&1 );
	len += sprintf( buf+len, "PAE=%X  ", (cr4>>5)&1 );
	len += sprintf( buf+len, "\n" );
	len += sprintf( buf+len, "cr3=%08X cr0=%08X\n",cr3,cr0);
	len += sprintf( buf+len, "pgd:0x%08X\n",(unsigned int)mm->pgd);
	len += sprintf( buf+len, "gdtr address:%lX, limit:%X\n", gdtr.address,gdtr.limit);
//	len += sprintf( buf+len, "cpu_gdt_table address:0x%08lX\n", cpu_gdt_table);

	return	len;
}


 int init_module( void )
 {
	printk( "<1>\nInstalling \'%s\' module\n", modname );
	create_proc_info_entry( modname, 0, NULL, my_get_info );
	return	0;  
 }


 void cleanup_module( void )
 {
	remove_proc_entry( modname, NULL );
	printk( "<1>Removing \'%s\' module\n", modname );
 }

 MODULE_LICENSE("GPL");

