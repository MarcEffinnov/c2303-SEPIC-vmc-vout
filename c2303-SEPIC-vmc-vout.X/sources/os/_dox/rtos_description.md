### RTOS Description {#rtos-description}

<p><a href="https://www.microchip.com" rel="nofollow"><img src="https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png" alt="Microchip Technology" style="max-width:100%;"></a></p>

The critical component is where CPU activity needs to get shared between different software-driven processes such as housekeeping background tasks, processing communication protocols and the software-based real-time feedback loop. As the CPU can only execute one instruction at the time, this process alignment is managed by the multi-priority level interrupt controller mentioned above.

Depending on the device generation, the CPU architecture of dsPIC33&reg; provides between 8 and 16 priority levels on which code can be executed. Interrupt nesting allows higher priority processes to interrupt lower priority processes. While a higher priority process is executed, the lower priority process is stopped at the point when the interrupt occurred. Its execution continues seamlessly after the high priority process has been completed. 

Priority level #0 is the lowest one and is continuously occupied by the main program, which is automatically started when the device comes out of reset. The highest priority level (#8 or #16) is reserved for so-called uninterruptible processes, such as fatal errors caused by a divide by zero, an address error, stack error or oscillator failure, which are the equivalent to a PC's blue screen error. These *fatal errors* will all lead to a CPU reset if not handled in software. All remaining priority levels can be selected by the user and used to arrange software processes to account for their individual importance, timing tolerance or required response time.

Depending on how many priority levels are staggered for simultaneous execution, the respective execution time of a process will be more deterministic the higher its priority level, resp. less deterministic the lower its priority level is. 

#### Example A: Single Interrupt

The CPU is running executing the main loop of the program on priority level #0. This routine is interrupted by another process called on priority level #2. Hence, the level #0 process is suspended until the process on priority level #2 has been executed and the CPU returns to priority level #0. 

<p>
  <center>
    \image html irq_p0-2.png width=580
  </center>
</p>
<p><center><i>Example A: Single Interrupt Process Alignment</i></center></p>


While the total execution time of the process on priority level #2 t(p2) in this example is deterministic, as it will be executed uninterrupted, the total execution time of the process on priority level #0 t(p0) will now be the sum of both processes t(p0) + t(p2). Hence, the priority level #2 process will behave more deterministic than the priority level #0 task.

#### Example B: Two Interrupts

However, if a even higher priority level #6 process is called while the process on priority level #2 is still active, the priority level #2 process gets also interrupted and suspended until the execution of the priority level #6 process has been completed. 

<p>
  <center>
    \image html irq_p0-2-6.png width=580
  </center>
</p>
<p><center><i>Example B: Two Interrupts Process Alignment</i></center></p>

Now the execution time of priority level #6 process is deterministic while the execution time of the priority level #2 process includes the execution time spend to execute the priority level #6 process. The total execution time of the priority level #0 process is now the sum of t(p0), t(p2) and t(p6).

#### Example C: Mixed Interrupt Priorities

To make things even more complex, we now introduce a fourth, simultaneous process on interrupt level #5, which occurs while the higher interrupt priority level #6 is still active. As priority #6 is higher than level #5, the priority level #5 process will be pending until the higher priority level #6 process has been completed. However, instead of stepping back down to the suspended priority level #2 process, the newly occurred priority level #5 process is executed first before the priority level #2 process is continued. The main program will be resumed once all higher priority levels have been completed.

<p>
  <center>
    \image html irq_p0-2-6-5.png width=640
  </center>
</p>
<p><center><i>Example C: Mixed Interrupt Priorities Process Alignment</i></center></p>

 - <b> Software Process Priority Guidelines</b>

As stated above, in a switched-mode power supply the real-time control loop always requires to have the highest priority in the system to ensure stable operation of the digital compensation filter including all potentially necessary real-time responses applied to the switching operation. In multi-loop control systems such as average current mode, multiple high-priority processes are usually triggered by the switching signal generator (i.e. PWM module) being distributed across a switching cycle to ensure uninterrupted, collision-free execution of each feedback loop.

The next lower level is commonly reserved for tasks, which are less time critical than the real-time control loops but only allow a limited amount of execution time jitter and require to be executed at a known, deterministic frequency. This is commonly true for the power supply state machine and fault monitor. This class of processes are called high-priority tasks. 

The lowest levels are reserved for uncritical tasks or tasks not relying on deterministic execution such as communication protocol responses, self-diagnostic functions, human-machine interface (HMI) operations or housekeeping functions. 

Each of these three basic levels may accept a certain amount of jitter in its execution period and or execution repetition frequency. Both properties may influence the reliability of a process and needs to be examined carefully to ensure the complete firmware remains stable, reliable and responsive. Slower tasks with comparatively long execution periods usually accept larger execution period jitter as well as are less reliant on a precise execution repetition frequency and therefore can be placed at lower priority levels. the more time critical a process, the shorter it execution time usually is, allowing to place it at higher priorities, frequently interrupting the lower priority tasks.

For example, processing a communication response includes multiple different steps such as receiving a certain number of data bytes, performing a cyclic redundancy check (CRC) validating, parsing command and data content, generating the response, handing the response back to the communication interface, monitoring the transmission of the response. Depending on the type of interface and transmission mechanism used, this process can take many milliseconds to complete and may occur every couple of seconds. Im comparison, a real-time control loop of a power supply may only take a couple of 100 nanoseconds to be executed at a repetition frequency of several 100 kHz. Hence, processing the communication protocol will potentially get interrupted thousands of times in one communication cycle. 

Hence, aligning low and high priority processes requires to break up the longer, more tolerant tasks in smaller sub-processes, which can be called in defined sequences, the so-called states. These states are then managed and monitored by individual sequencers called state machines. The more processes need to run in parallel, the smaller the individual states of a state machine need to be to allow most effective interleaving of parallel processes.


_________________________________________________
(c) 2022, Microchip Technology Inc.

