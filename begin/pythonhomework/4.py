def cost_function(x):
    return x**3 - 6*x**2 + 15*x

def extra_cost_to_produce_one_more(x):
    current_cost = cost_function(x)
    one_more_cost = cost_function(x + 1)
    extra_cost = one_more_cost - current_cost
    return extra_cost

# Current production (radiators per day)
current_production = 10

# Calculate the extra cost to produce one more radiator
extra_cost = extra_cost_to_produce_one_more(current_production)

# Print the result
print(f"Current production: {current_production} radiators per day")
print(f"Extra cost to produce one more radiator: ${extra_cost}")
