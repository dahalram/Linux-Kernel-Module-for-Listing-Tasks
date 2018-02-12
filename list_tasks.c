#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>

int list_tasks_init(void) {
	struct task_struct *task;
		
	printk(KERN_INFO "Loading module\n");
	for_each_process(task) {
		printk(KERN_INFO "pid: %d, pname: %s, state: %ld\n", task->pid, task->comm, task->state); 
	

		if (task->parent) {
			struct task_struct *t_parent;
			t_parent = task->parent;
			printk(KERN_INFO "parent pid: %d, parent pname: %s, parent state: %ld\n", t_parent->pid, t_parent->comm, t_parent->state);
		}
	
	}
	return 0;	
}

void list_tasks_delete(void) {
	printk(KERN_INFO "Removing Module\n");
}

module_init(list_tasks_init);
module_exit(list_tasks_delete);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Module for Listing Tasks");
MODULE_AUTHOR("Ram D");
