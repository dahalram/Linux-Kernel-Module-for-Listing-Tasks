#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>

int list_tasks_init(void) {
	struct task_struct *task;
	
	
	return 0;	
}

int list_tasks_delete(void) {
	printk(KERN_INFO "Removing Module\n");
}

module_init(list_tasks_init);
module_exit(list_tasks_delete);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Module for Listing Tasks");
MODULE_AUTHOR("Ram D");
