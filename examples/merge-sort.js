const a = [1, 3, 5, 1, 3, 4, 3, 2, 66, 32, 21, 2, 4, 55, 23, 1]

function mergeSort(xs = []) {
  if (xs.length === 0) return []
  if (xs.length === 1) return xs
  if (xs.length === 2) {
    return [Math.min(...xs), Math.max(...xs)]
  }

  const pv = Math.floor(xs.length / 2)
  const ys = mergeSort(xs.slice(0, pv))
  const hs = mergeSort(xs.slice(pv))

  return merge(ys, hs)
}

function merge(xs = [], ys = []) {
  let x = 0
  let y = 0

  while (x < xs.length && y < ys.length) {
    if (xs[x] <= ys[y]) {
      x++;
      continue
    }

    xs.splice(x, 0, ys[y])
    y++
  }

  return xs.concat(ys.slice(y))
}


const xs = a.slice(0)
console.time("js-sort")
console.log("js-sort", JSON.stringify(xs.sort((aa, b) => aa - b)))
console.timeEnd("js-sort")

const ys = a.slice(0)
console.time('merge-sort')
console.log("merge-sort", JSON.stringify(mergeSort(ys)))
console.timeEnd('merge-sort')


console.log("-> unsorted after", JSON.stringify(a))
// console.log("-> sorted", mergeSort(a))