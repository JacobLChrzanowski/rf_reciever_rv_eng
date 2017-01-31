# rf_reciever_rv_eng
Arduino Reverse-Engineering Receiver code


This project was the result of a faulty string of Chrsitmas lights that utilized an rf transmitter falling into my lap. I reverse engineered the rf signals broadcasted by a handheld remote and found that distinguishable patterns emerged. This was an exercise in filtering noise more than anything, as the rf module was "dumb" and would send a high signal down the data pin to the arduino anytime it detected any sort of rf activity on the 433 Mhz band. It utilizes "magic numbers" which I will fix sometime soon.
