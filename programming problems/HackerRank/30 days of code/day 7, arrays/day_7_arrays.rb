#!/bin/ruby

n = gets.strip.to_i
arr = gets.rstrip.split.map(&:to_i)
arr.reverse_each { |value| print value, " "}