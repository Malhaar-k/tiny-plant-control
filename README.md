# Low cost plant model simulation 

Model based adaptive algorithms in control systems require an internal model to act as a reference for the controller. This project aims to make it easier to implement such control strategies.

### NOTE: This project is specifically for generating real-time plant output

## Methods
This project uses two implementations for simulating a tiny plant:
- Descrete time domain plant (Use "tf_descrete.h")
- State space represented plant (Use "tf_statespace.h")

I personally recommend using the state space representation since it lets the user emulate a MIMO system.


## Future Work:
- [ ] Test how many clock cycles it requires for each step.
- [ ] Test with `tf_descrete.h`
- [ ] Implement better descrete integration method.
- [ ] Better documentation
- [ ] Check if other matrix libraries reduce execution time.
