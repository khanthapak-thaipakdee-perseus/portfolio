Assignment_2_1_compare_MIT_based_with_modified_MIT_based contains:

- Simulink scheme of the MIT-based DC motor controller with gamma = 1
- Comparison of the MIT-based DC motor controller with modified MIT-based MRAS controller (which is my model)
- In the MIT Modified MRAS subsystem, you will find adjustment of sub-blocks.
- Results can be seen in the scope named y-ym_MIT_compare.


Assignment_2_gamma_(0.01/0.1/1/3/5)  contains

- The number after gamma indicates the value of gamma used in each simulation file.
- Simulink scheme of the MIT-based DC motor controller
- Simulink scheme of the Lyapunov-based DC motor controller
- Six scopes; y-ym MIT, eMIT, y-ym_lyp, e_lyp, y-ym_MIT_Lyp, and y-e_MIT-Lyp

	y-ym shows the outputs y and ym.
	e shows the error.
	"MIT" refers to MIT rule.
	"lyp" refers to Lyapunov stability theory.
	y-ym_MIT_Lyp will compares the outputs y and ym from both methods.
	y-e_MIT-Lyp will compares the output y and the error from both methods.