from matplotlib import pyplot as plt
import numpy as np

positions = ['Cash','ALB','ARM','ARTL','ENPH','EQNR','FBGRX','FFFEX','FSMAX','FTBFX','FXAIX','HUM','TSM']
data = [0.46,0.02,24.95,0,74.15,0.04,0.23,0.01,0.01,0,0.01,0.02,0.09]

fig = plt.figure(figsize=(10,7))
plt.pie(data, labels=positions)
plt.show()
