import numpy as np
import pandas as pd
hidden_states = ['Sunny', 'Rain', 'Foggy']
pi = [0, 0.2, 0.8]
state_space = pd.Series(pi, index=hidden_states, name='states')
a_df = pd.DataFrame(columns=hidden_states, index=hidden_states)
a_df.loc[hidden_states[0]] = [0.8, 0.05, 0.15]
a_df.loc[hidden_states[1]] = [0.2, 0.6, 0.2]
a_df.loc[hidden_states[2]] = [0.2, 0.3, 0.5]
print("\n HMM matrix:\n", a_df)
a = a_df.values

# observable_states = states
# b_df = pd.DataFrame(columns=observable_states, index=hidden_states)
# b_df.loc[hidden_states[0]] = [1,0]
# b_df.loc[hidden_states[1]] = [0.8,0.2]
# b_df.loc[hidden_states[2]] = [0.3,0.7]
# print("\n Observable layer  matrix:\n",b_df)
# b = b_df.values
x = a_df[hidden_states[0]][0]*a_df[hidden_states[1]][0]
print("Sunny|Sunny",a_df[hidden_states[0]][0])
print("Rainy|Sunny",a_df[hidden_states[1]][0])
print("Today Sunny, Tomorrow Sunny, Then Rainy: ",x)
