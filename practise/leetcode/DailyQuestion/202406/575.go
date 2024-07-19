func distributeCandies(candyType []int) int {
	ctmp := make(map[int]int)
	for _, e := range candyType {
		ctmp[e]++
	}
	ans := len(candyType) / 2
	if len(ctmp) < ans {
		return len(ctmp)
	}
	return ans
}

func distributeCandies(candyType []int) int {
    set := map[int]struct{}{}
    for _, t := range candyType {
        set[t] = struct{}{}
    }
    return min(len(set), len(candyType)/2)
}
