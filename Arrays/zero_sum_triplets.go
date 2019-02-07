// Given an array of distinct elements. The task is to find triplets in array whose sum is zero.
// https://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

func main() {
	array := takeUserInput()
	findZeroSumTriplets(array)
}

func takeUserInput() []int {
	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter array of integers: ")
	input, err := reader.ReadString('\n')
	if err != nil {
		log.Fatal(err)
	}

	strs := strings.Split(input[0:len(input)-1], " ")
	integers := make([]int, len(strs))
	for i, str := range strs {
		integers[i], err = strconv.Atoi(str)
		if err != nil {
			log.Fatal(err)
		}
	}

	return integers
}

func findZeroSumTriplets(array []int) {
	found := false
	arrayLen := len(array)
	for i := 0; i < arrayLen-2; i++ {
		for j := i + 1; j < arrayLen-1; j++ {
			for k := j + 1; k < arrayLen; k++ {
				if array[i]+array[j]+array[k] == 0 {
					fmt.Println(array[i], array[j], array[k])
					found = true
				}
			}
		}
	}

	if found == false {
		fmt.Println("No zero sum triplets found")
	}
}

