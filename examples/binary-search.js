const a = [1, 3, 5, 1, 3, 4, 3, 2, 66, 32, 21, 2, 4, 55, 23, 1]

a.sort((aa, b) => aa - b)

console.log("a is", JSON.stringify(a))

function includes(arr = [], x) {
  if (arr.length === 0) return false
  return binSearch(arr, x)
}

function binSearch(arr = [], x, l = 0, h = arr.length, step = 0) {
  const pv = Math.floor((l + h) / 2)
  console.log("step is", step)

  if (arr[pv] === x) return true
  if (l === h - 1) return false

  if (arr[pv] < x) return binSearch(arr, x, pv, h, step + 1)
  return binSearch(arr, x, l, pv, step + 1)
}

console.log("includes", includes(a, 66))