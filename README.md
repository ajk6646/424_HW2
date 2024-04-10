# 424_HW2
Hello, whoever is grading this homework assignment!

I figured it would be easiest to add my answers to questions 5 and 6 here since it is just a written response. 

5. If the robot that just finished a task begins a new task immediately, it would create an infinite loop where the two robots that are actively doing tasks will continue doing tasks indefinitely. This would never allow the simulation to finish as the finishing scenario is all the robots finishing all their tasks. One solution would be to create a queue that each robot must enter before beginning their task. This would result in the robot that just finished its tasks (and assigned a new one) having to go to the end of the queue and allow the other robots to collect the needed tools and complete their tasks.

6. The biggest issue is that all the planes cannot check in with the ATC at once. Additionally, waking someone up takes a good chunk of time and a person is usually groggy which leads to inefficiency and mistakes. With making each step take time, there would be a lot of excess time between a plane entering the traffic pattern and landing. I theorize that this delay time would result in Aircraft 1 landing and Aircraft 2, 3, and 4 entering the queue and then landing. All other planes would be diverted to another airport. A potential solution would be to get an additional ATC. 

Let me know if you need help understanding my code. :)

Additionally, I worked with Marty Mullen and Eric Valentine on this assignment.

Aaron Kern
