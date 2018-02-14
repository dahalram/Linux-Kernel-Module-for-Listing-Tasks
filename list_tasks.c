#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>

int list_tasks_init(void) {
	
	struct task_struct *task;
		
	printk(KERN_INFO "Loading module\n");
	for_each_process(task) {
		printk(KERN_INFO "Child:: pname: %s, state: %ld, pid: %d\n", task->comm, task->state, task->pid); 
	
		unsigned int i = 0;
		if (task->parent) {
			struct task_struct *t_parent;
			t_parent = task->parent;
			//printk(KERN_INFO "parent pid: %d, parent pname: %s, parent state: %ld\n", t_parent->pid, t_parent->comm, t_parent->state);
		
		
			while (t_parent->pid != 0) {
				//struct task_struct *t_parent; 
				//t_parent = task->parent;
				printk(KERN_INFO "Parent %d :: pname: %s, parent state: %ld, pid: %d\n", i, t_parent->comm, t_parent->state, t_parent->pid);
				i = i + 1;
				t_parent = t_parent->parent;
			}
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
