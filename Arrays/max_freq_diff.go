// Maximum difference between frequency of two elements such that element having greater frequency is also greater
// https://www.geeksforgeeks.org/maximum-difference-between-frequency-of-two-elements-such-that-element-having-greater-frequency-is-also-greater/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
	"strconv"
	"strings"
)

// takeUserInput ...
func takeUserInput() []int {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter integers: ")
	line, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}

	strs := strings.Split(line[0:len(line)-1], " ")
	integers := make([]int, len(strs))
	for i, str := range strs {
		integers[i], err = strconv.Atoi(str)
		if err != nil {
			log.Fatal(err)
		}
	}

	return integers
}

// min returns minimum of 2 integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// max returns maximum of 2 integers
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// maxFreqDiff finds maximum difference in frequencies of elements in array
func maxFreqDiff(array []int) int {
	m := make(map[int]int)
	distinct := []int{}

	// Populate map with element of array to frequency
	// And append distinct elements to an array
	for _, v := range array {
		if _, exists := m[v]; !exists {
			distinct = append(distinct, v)
		}

		m[v]++
	}

	// Sort distinct value array
	sort.Ints(distinct)

	// Iterate over distinct values and maintain minFreq and maxDiff
	minFreq := len(array) + 1
	maxDiff := 0
	for i := 0; i < len(distinct); i++ {
		currFreq := m[distinct[i]]
		maxDiff = max(maxDiff, currFreq-minFreq)
		minFreq = min(minFreq, currFreq)
	}

	return maxDiff
}

// main Driver
func main() {
	array := takeUserInput()
	maxDiff := maxFreqDiff(array)
	fmt.Println(maxDiff)
}
