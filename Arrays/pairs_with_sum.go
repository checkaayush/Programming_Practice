// Given array of integers and a sum value S, find all pairs of integers
// whose sum is S

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

// main Driver
func main() {
	array, sum := takeUserInput()
	printPairsWithSum(array, sum)
}

// takeUserInput ...
func takeUserInput() ([]int, int) {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter array with sum at the end: ")
	line, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}

	strs := strings.Split(line[:len(line)-1], " ")
	integers := make([]int, len(strs))
	for i, s := range strs {
		integers[i], err = strconv.Atoi(s)
		if err != nil {
			log.Fatal(err)
		}
	}

	sum := integers[len(strs)-1]
	integers = integers[:len(strs)-1]

	return integers, sum
}

// printPairsWithSum Prints all pairs of integers in input arr
// whose sum is equal to the given sum. O(n) time, O(n) space
func printPairsWithSum(arr []int, sum int) {
	found := false

	m := make(map[int]bool)
	for _, v := range arr {
		// Check if sum-v exists in map
		if _, exists := m[sum-v]; exists {
			found = true
			fmt.Println(v, sum-v)
		} else {
			m[v] = true
		}
	}

	if found == false {
		fmt.Println("No such pair found.")
	}
}
