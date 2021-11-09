echo "dma1: A device that needs a lot of data, interrupts and ports can pose a heavy load on the cpu. With dma or Direct Memory Access a device can gain (temporary) access to a specific range of the ram memory." > ex1.txt
echo "pic1: The Programmable Interrupt Controller (PIC) is one of the most important chips making up the architecture. Without it, the x86 architecture would not be an interrupt driven architecture. Its function is to manage hardware interrupts and send them to the appropriate system interrupt. This allows the system to respond to devices needs without loss of time (from polling the device, for instance)." >> ex1.txt
echo "timer1: Timers are used to schedule execution of a function (a timer handler) at a particular time in the future. They thus work differently from task queues and tasklets in that you can specify when in the future your function will be called, whereas you can’t tell exactly when a queued task will be executed. On the other hand, kernel timers are similar to task queues in that a function registered in a kernel timer is executed only once—timers aren’t cyclic. " >> ex1.txt

sudo cat /proc/ioports >> ex1.txt

