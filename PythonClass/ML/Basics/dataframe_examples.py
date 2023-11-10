'''

'''

import pandas as pd

#data dictionary to dataframe
data_dict = {
    "Name": ['A','B','C'],
    "Color": ['Blue'],
    "Index": [4,5,6,7]
}

df = pd.DataFrame(data_dict)
print(df)
