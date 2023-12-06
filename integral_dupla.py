import numpy as np

def simpson_integral_of_y(func, ay, by, ny):
    def integral_x(x):
        hy = (by - ay) / ny
        integral = 0.0

        for j in range(ny + 1):
            y = ay + j * hy
            if j == 0 or j == ny:
                wy = 1/3
            elif j % 2 == 1:
                wy = 4/3
            else:
                wy = 2/3

            integral += func(x, y) * wy * hy

        return integral

    return integral_x

def example_func(x, y):
    return np.sin(x) + np.cos(y)  # Uma funcao exemplo

def double_integral(func, ax, bx, nx, ay, by, ny):
    # Primeiro, integramos em relacao a y para cada x
    integral_func_of_x = simpson_integral_of_y(func, ay, by, ny)

    # Agora, integramos essa funcao resultante em relacao a x
    hx = (bx - ax) / nx
    integral = 0.0

    for i in range(nx + 1):
        x = ax + i * hx
        if i == 0 or i == nx:
            wx = 1/3
        elif i % 2 == 1:
            wx = 4/3
        else:
            wx = 2/3

        integral += integral_func_of_x(x) * wx * hx

    return integral

# Limites de integracao e numero de intervalos para y
ay, by, ny = 0, np.pi, 10

# Testando a funcao com a funcao exemplo
ax, bx, nx = 0, np.pi, 10  # Limites de integracao e numero de intervalos para x

# Calculo da integral dupla
double_integral_result = double_integral(example_func, ax, bx, nx, ay, by, ny)
double_integral_result

print(double_integral_result)

# Obtem a funcao resultante
resulting_function = simpson_integral_of_y(example_func, ay, by, ny)

# Exemplo de uso da funcao resultante para um valor especifico de x
x_example = 1.0
result_for_x = resulting_function(x_example)

