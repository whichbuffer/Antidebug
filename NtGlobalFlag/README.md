### Complexity Low

# Description

NtGlobalFlag is a similar technique like IsDebuggerPresent, because both of them read values from PEB Structure to detect if the Software is debugged or not.  NtGlobalFlag is also located in the PEB Structure, when the process is being debugged the NtGlobalFlag is set to 0x70. 

Below picture from WinDBG is showing the PEB Structure when the Software is being debugged :   

![2](https://user-images.githubusercontent.com/42712921/184474254-a11ad572-9a06-4b98-82a7-9ab74074a5f7.PNG)

We developed our Software to show a error message then exit itself, whenever the NtGlobalFlag equal to 0x70 : 

![1](https://user-images.githubusercontent.com/42712921/184474306-7daf0fd9-d19f-4190-b035-0f64a641e1b5.PNG)

## Reversing Technique (Tips & Tricks)

In order to evade this Anti Debugging technique, we can use a similar tactic just like on IsDebuggerPresent or we can hide our PEB Structure while debugging on x64DBG, I will show both of them 

NULL the RAX :

After setting breakpoint at the return (ret) of the Anti debugging function, we can now step over to ret then change the RAX data to 0, this will evade the Anti Debugging technique which is same as like IsDebuggerPresent one


![RAX](https://user-images.githubusercontent.com/42712921/184475907-d5a027dd-8493-4bba-952a-04e5825fbef7.PNG)

Change the value from RAX register (x64)

![NULL](https://user-images.githubusercontent.com/42712921/184475892-90fb5583-7972-40a9-90d7-1004327ac3b1.PNG)

After the execution we can see it beat the Anti Debugging :


![wİN](https://user-images.githubusercontent.com/42712921/184475933-c59c7c58-5857-437c-8cd9-04ac11a1b573.PNG)


We can also able to automate this process by an awesome feature of  x64DBG, it help us to hide our PEB Structure which means, debugged software no longer read data from PEB
![Animation](https://user-images.githubusercontent.com/42712921/184476023-46a9bec2-8eb5-4f97-b4b1-9b0d4107686b.gif)


