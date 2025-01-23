### RTOS Applications {#rtos6g2}

<p><a href="https://www.microchip.com" rel="nofollow"><img src="https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png" alt="Microchip Technology" style="max-width:100%;"></a></p>

#### Real-Time Operating System for Real-Time Control Applications, Version 6G2

#### Description
RTOS allows to sequence and prioritize multiple tasks which are defined as applications. As a consequence, it allows for user to add/remove, enable/disable, change priority, change frequency of given tasks.

Applications/Tasks are configured in `/sources/config/apps.c`.

Priority level  is key to not disturb real-time constraints of Digital Control. Thus, some key applications such as `appPowerSupply` and `appFaultMonitor` are defined as high priority (`APP_CLASS_HIGH_PRIORITY`) and are run at each RTOS execution cycle (call tick):
- `.Settings.Period = 0`
- `.Settings.Offset = 0`

#### Applications Used In This Example
Applications sets in `/sources/config/apps.c`.

- `appPowerSupply`: This application does manage the 4-Switch Buck-Boost power supply actions. `appPowerSupply_Execute` is the function called at each RTOS call tick to define actions required (if any) and does run power supply State Machine.
```c
        volatile struct APPLICATION_TASK_s appPowerSupply = 
        {
            .Functions.Initialize = &appPowerSupply_Initialize, ///< Pointer to user task INITIALIZATION function
            .Functions.Start      = &appPowerSupply_Start,      ///< Pointer to user task START function
            .Functions.Execute    = &appPowerSupply_Execute,    ///< Pointer to user task EXECUTE function
            .Functions.Dispose    = &appPowerSupply_Stop,       ///< Pointer to user task DISPOSE/STOP function

            .Settings.execClass   = APP_CLASS_HIGH_PRIORITY,    ///< Application task lass (high- or low-priority)
            .Settings.Period      = 0,                          ///< Task execution period in (n-1) OS task manager call ticks 
            .Settings.Offset      = 0,                          ///< Task execution offset in (n-1) OS task manager call ticks
            
            .Status.enabled       = true                        ///< Enable this task right after startup
        };
``` 

- `appFaultMonitor`: This application does manage the configuration and management of Faults defined in `/sources/fault_handler/app_fault_monitor.h` (*Note:* Each fault is configured in `/sources/fault_handler/app_fault_config.c`).
```c
        volatile struct APPLICATION_TASK_s appFaultMonitor = 
        {
            .Functions.Initialize = &appFaultMonitor_Initialize, ///< Pointer to user task INITIALIZATION function
            .Functions.Start      = &appFaultMonitor_Start,      ///< Pointer to user task START function
            .Functions.Execute    = &appFaultMonitor_Execute,    ///< Pointer to user task EXECUTE function
            .Functions.Dispose    = &appFaultMonitor_Dispose,    ///< Pointer to user task DISPOSE function

            .Settings.execClass   = APP_CLASS_HIGH_PRIORITY,    ///< Application task lass (high- or low-priority)
            .Settings.Period      = 0,                          ///< Task execution period in (n-1) OS task manager call ticks 
            .Settings.Offset      = 0,                          ///< Task execution offset in (n-1) OS task manager call ticks

            .Status.enabled       = true                        ///< Enable this task right after startup
        };
``` 

- `appButton`: This application does manage the configuration and sensing of User button SW4 (which is, by default, used to start 4-Switch Buck/Boost converter).
```c
        volatile struct APPLICATION_TASK_s appButton = 
        {
            .Functions.Initialize = &button_Initialize, ///< Pointer to user task INITIALIZATION function
            .Functions.Start      = &button_Start,      ///< Pointer to user task INITIALIZATION function
            .Functions.Execute    = &button_Execute,    ///< Pointer to user task INITIALIZATION function
            .Functions.Dispose    = &button_Stop,    ///< Pointer to user task INITIALIZATION function
            
            .Settings.execClass   = APP_CLASS_LOW_PRIORITY, ///< Application task lass (high- or low-priority)
            .Settings.Period      = 100,                ///< Task execution period in OS task manager call ticks => 10ms
            .Settings.Offset      = 40,                  ///< Task execution offset in OS task manager call ticks
            
            .Status.enabled       = true                ///< Enable this task right after startup
        };
```

- `appLed`: This application does manage debug LED LD1 used as SW running flah (1s toggling) and Fault detection flag (high speed toggling).
```c
        volatile struct APPLICATION_TASK_s appLed = 
        {
            .Functions.Initialize = &appLED_Initialize, ///< Pointer to user task INITIALIZATION function
            .Functions.Start      = &appLED_Start,      ///< Pointer to user task INITIALIZATION function
            .Functions.Execute    = &appLED_Execute,    ///< Pointer to user task INITIALIZATION function
            .Functions.Dispose    = &appLED_Dispose,    ///< Pointer to user task INITIALIZATION function
            
            .Settings.execClass   = APP_CLASS_LOW_PRIORITY, ///< Application task lass (high- or low-priority)
            .Settings.Period      = 1000,               ///< Task execution period in OS task manager call ticks
            .Settings.Offset      = 0,                  ///< Task execution offset in OS task manager call ticks
            
            .Status.enabled       = true                ///< Enable this task right after startup
        };
```


#### Usage Examples

When User needs to setup a new application, following steps are required:
- Create application folder under `/sources/<new_application_name>`
- Create sub-folder `app` which will contain the new application `.h` and `.c` files (follow example template as for `app_Led.h` and `app_Led.c` application)
- Once `Initialize`, `Start`, `Execute`, `Dispose` functions are declared and designed, put `#include ../<new_application_name>/<new_application_name>.h` in `/sources/config/apps.h`
- In `/sources/config/apps.c`, add new application configuration:
```c
        volatile struct APPLICATION_TASK_s <new_application_name> = 
        {
            .Functions.Initialize = &<new_application_name>_Initialize, ///< Pointer to user task INITIALIZATION function
            .Functions.Start      = &<new_application_name>_Start,      ///< Pointer to user task INITIALIZATION function
            .Functions.Execute    = &<new_application_name>_Execute,    ///< Pointer to user task INITIALIZATION function
            .Functions.Dispose    = &<new_application_name>_Dispose,    ///< Pointer to user task INITIALIZATION function
            
            .Settings.execClass   = APP_CLASS_LOW_PRIORITY, ///< Application task lass (high- or low-priority)
            .Settings.Period      = <occurence>,               ///< Task execution period in OS task manager call ticks
            .Settings.Offset      = <offset>,                  ///< Task execution offset in OS task manager call ticks
            
            .Status.enabled       = true                ///< Enable this task right after startup
        };
```
- In `/sources/config/apps.c`:
    - add new application in execution sequence queue by updating following code (new application must be put at rank where it should be executed):
```c
        volatile struct APPLICATION_TASK_s* Queue_ExecuteSequence[] =
        {
            &appLed,          ///< Task #0: LED Task
            &appButton,         ///< Task #1: Demo Task
            &appPowerSupply,  ///< Task #2: Power Supply Control Task
            &appFaultMonitor,  ///< Task #3: Fault Monitor Task
            &<new_application_name> ///< Task #n: New Application Task
        };
```
    - add new application in start sequence queue by updating following code (new application must be put at rank where it should be started):
```c
        volatile struct APPLICATION_TASK_s* Queue_StartSequence[] =
        {
            &appLed,          ///< Task #0: LED Task
            &appButton,         ///< Task #1: Demo Task
            &appPowerSupply,  ///< Task #2: Power Supply Control Task
            &appFaultMonitor,  ///< Task #3: Fault Monitor Task
            &appAgc,            ///< Task #4: AGC calculation
            &<new_application_name> ///< Task #n: New Application Task
        };
```
    - add new application in Initialize sequence queue by updating following code (new application must be put at rank where it should be initialized):
```c
        volatile struct APPLICATION_TASK_s* Queue_InitializeSequence[] =
        {
            &appLed,          ///< Task #0: LED Task
            &appButton,         ///< Task #1: Demo Task
            &appPowerSupply,  ///< Task #2: Power Supply Control Task
            &appFaultMonitor,  ///< Task #3: Fault Monitor Task
            &appAgc,            ///< Task #4: AGC calculation
            &<new_application_name> ///< Task #n: New Application Task
        };
```
    - add new application in Stop sequence queue by updating following code (new application must be put at rank where it should be stopped):
```c
        volatile struct APPLICATION_TASK_s* Queue_StopSequence[] =
        {
            &appLed,          ///< Task #0: LED Task
            &appButton,         ///< Task #1: Demo Task
            &appPowerSupply,  ///< Task #2: Power Supply Control Task
            &appFaultMonitor,  ///< Task #3: Fault Monitor Task
            &appAgc,            ///< Task #4: AGC calculation
            &<new_application_name> ///< Task #n: New Application Task
        };
```
