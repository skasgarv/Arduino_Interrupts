# Arduino_Interrupts

An attempt to work on Arduino Interrupts. Repository consists of two approaches.
  a. One time interrupt approach by using detachInterrupt(pin_number);
  b. Volatile approach allowing multiple usage of Interrupt routing
  
The Arduino Uno has two interrupt pins. Pin 2 assigned as Interrupt 0 and Pin 3 assigned as Interrupt 1.
We make use of attachInterrupt() function to achieve interrupt handling.

attachInterrupt takes in three arguments. 
attachInterrupt(Pin_number assigned value, Interrupt function, "Rising"/"Falling");

"Rising"/"Falling" depends on what value we assign the pin with in the setup function. If the value of Pin 2(Interrupt 0) is set as High,
any interrupt pressed would fall from high to low. Thus we use "Falling". And vice versa.

In our code, we have not performed any operation. We have just found the difference in time from the beginning of the program until the
interrupt has occurred.

We can perform operations in void loop() function and when interrupt occurs, we can perform required operations in the interrupt handler.

We need to make sure not to call interrupts within the interrupt handler and there are certain functions such as millis() which can be 
incremented in the interrupt handler. That is, if I use millis() at the beginning of the interrupt handler and again use millis() at the
end of the handler, there would be no change in millis() output even though time would have elapsed.
