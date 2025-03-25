import random

# Define the function to be maximized
def fitness(x):
    return -x**2 + 5

# Generate an initial population
def generate_population(size, x_min, x_max):
    return [random.randint(x_min, x_max) for _ in range(size)]

# Select parents based on fitness (tournament selection)
def select_parents(population):
    tournament = random.sample(population, 3)
    return max(tournament, key=fitness), max(tournament, key=fitness)

def crossover(parent1, parent2):
    point = random.randint(1, 4) 
    mask = (1 << point) - 1
    child1 = (parent1 & mask) | (parent2 & ~mask)
    child2 = (parent2 & mask) | (parent1 & ~mask)
    return child1, child2


def mutate(x):
    mutation_point = random.randint(0, 4)
    return x ^ (1 << mutation_point)


def genetic_algorithm(pop_size, generations, mutation_rate):
    population = generate_population(pop_size, 0, 31)
    
    for gen in range(generations):
        new_population = []
        for _ in range(pop_size // 2):
            parent1, parent2 = select_parents(population)
            child1, child2 = crossover(parent1, parent2)
            if random.random() < mutation_rate:
                child1 = mutate(child1)
            if random.random() < mutation_rate:
                child2 = mutate(child2)
            new_population.extend([child1, child2])
        population = new_population
        
        best_solution = max(population, key=fitness)
        print(f'Generation {gen + 1}: Best x = {best_solution}, f(x) = {fitness(best_solution)}')
    
    return best_solution, fitness(best_solution)


best_x, best_fitness = genetic_algorithm(pop_size=10, generations=20, mutation_rate=0.1)
print(f'Final Best solution: x = {best_x}, f(x) = {best_fitness}')
