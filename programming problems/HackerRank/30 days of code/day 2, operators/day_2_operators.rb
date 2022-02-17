#!/bin/ruby

require 'json'
require 'stringio'

#
# Complete the 'solve' function below.
#
# The function accepts following parameters:
#  1. DOUBLE meal_cost
#  2. INTEGER tip_percent
#  3. INTEGER tax_percent
#

def solve(meal_cost, tip_percent, tax_percent)
    # Write your code here
    puts "%.0f" % (meal_cost + meal_cost*tip_percent/100 + meal_cost*tax_percent/100)
end

meal_cost = gets.strip.to_f

tip_percent = gets.strip.to_i

tax_percent = gets.strip.to_i

solve meal_cost, tip_percent, tax_percent
