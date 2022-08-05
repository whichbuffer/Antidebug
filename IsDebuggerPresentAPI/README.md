### Complexity Low


# Description

One of the most widely used anti-debugging techniques is called IsDebuggerPresent(), this simple API call used so oftenly by malware developers because it’s relatively  easy to use.  

The function kernel32!IsDebuggerPresent() determines whether the current process is being debugged by a user-mode debugger such as x64dbg. Generally, the function only checks the BeingDebugged flag of the Process Environment Block (PEB), if the BeingDebugged flag is true then malware exits itself without executing any malicious functions.

**Example of Assembly Code**

![1](https://user-images.githubusercontent.com/42712921/183047524-b90d3331-7f3a-4409-b183-d5716971c9df.PNG)


![2](https://user-images.githubusercontent.com/42712921/183048001-122e005e-0d4c-4142-a582-337d54d0b5c7.png)


# Reversing Technique (Tips & Tricks)

In order to perform a Reverse Engineering on this example, we write a dummy application to understand the anti-debugging technique itself and tips for malware analysts on how to defeat that.

We can examine the compiled dummy application on IDA pro, it can show us the basic usage of IsDebuggerPresent() API, we can read that Assembly code as; if this application is debugging then go to the ExitProcess function else do some evil things. 

![6](https://user-images.githubusercontent.com/42712921/183048940-1fe8a3a4-b9db-45e1-832e-3dc0992c0ed4.PNG)

So the question is how to evade that anti-debug check and continue the execution. After setting breakpoint on IsDebuggerPresent() API, we can step through and examine the RAX register on the debugger, we can clearly see that it stores a boolean data which is 1 (True).

![7](https://user-images.githubusercontent.com/42712921/183051053-b03b1adf-a85f-4df1-83bc-5cf0f262e01e.PNG)

Remember,  kernel32!IsDebuggerPresent() is looking for the BeingDebugged flag inside the PEB Structure, that flag only has true or false data which is boolean, if we can set this RAX data to 0 we can easily evade this anti-debugging.


![9](https://user-images.githubusercontent.com/42712921/183051132-f1b998f3-b4f3-4c3a-aeb9-6e65e33e29ea.PNG)

After setting the RAX to 0, we can now execute the code.



https://user-images.githubusercontent.com/42712921/183051452-28811640-6a72-4e75-96de-f7213d7a030e.mp4





