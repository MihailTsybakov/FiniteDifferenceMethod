import matplotlib.pyplot as plt

def get_data(filename : str):
    input_file = open(filename, 'r')
    whole_data = input_file.read()
    
    value_pairs = whole_data.split('\n')
    
    X  =  list(map(lambda pair: float((pair.split(' '))[0]), value_pairs))
    Val = list(map(lambda pair: float((pair.split(' '))[1]), value_pairs))
    
    return (X, Val)

filename = str(input('Enter filename: '))

X, Val = get_data(filename)

plt.plot(X, Val)

