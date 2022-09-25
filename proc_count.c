#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/sched.h>
#include <linux/init.h> 

struct proc_dir_entry* proc_count_file;

static int proc_count_show(struct seq_file* f, void* v) {
	int count = 0;
	for_each_process(t) {
		count++;
	}
	seq_printf(f, count);
	return 0;
}

static int __init proc_count_init(void)
{
	pr_info("proc_count: init\n");
	struct task_struct* t;
	proc_count_file = proc_create_single("count", 0444, NULL, proc_count_show);
	return 0;
}

static void __exit proc_count_exit(void)
{
	proc_remove(proc_count_file);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Your name");
MODULE_DESCRIPTION("One sentence description");
MODULE_LICENSE("GPL");
