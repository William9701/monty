,>,                                               Read the first digit and store in the first memory cell
>,                                                 Read the second digit and store in the second memory cell
[                                                   Start multiplication loop
  [-<+>]<                                           Move the second digit to the first memory cell
  >+                                                Increment the counter in the third memory cell
  <-                                                Decrement the first memory cell
]
>>>++++++++++<[->-<]>++++++++++<.                   Adjust and output the result
