function isSplitable(xs, x) {
  const splited = xs.split(x)
  return splited.every(x => x === "")
}

function algo(bs, ss, prevGcd) {
  if (ss.length === 0) return ""
  if (isSplitable(bs, ss)) return ss

  const divisor = gcd(bs.length, ss.length)
  if (divisor === prevGcd) return ""

  const res = splitEvery(ss, divisor)
  const ret = res.every(x => x === res[0]) && isSplitable(bs, res[0])
  return ret ? res[0] : ""
}

function splitEvery(str, n) {
  const res = []
  const dist = str.length / n

  for (let j = 0; j < dist; j++) {
    let temp = ""
    for (let i = 0; i < n; i++) {
      temp += str[j * n + i]
    }
    res.push(temp)
  }

  return res
}

function gcd(a, b) {
  if (!b) {
    return a;
  }

  return gcd(b, a % b);
}

function run(str1, str2) {
  const [bs, ss] = sorted(str1, str2)
  return algo(bs, ss)
}

function sorted(str1, str2) {
  if (str1.length > str2.length) return [str1, str2]
  return [str2, str1]
}

function test1() {
  let a = "ABABAB"
  let b = "AB"
  const r1 = run(a, b)
  const r2 = run(b, a)
  console.assert(r1 === r2, "r1 === r2", r1, r2)
  console.assert(r1 === "AB", "r1 should be equal to 'AB'", r1)
}

function test2() {
  let a = "TAUXXTAUXXTAUXXTAUXXTAUXX"
  let b = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"
  const r1 = run(a, b)
  const r2 = run(b, a)
  console.assert(r1 === r2, "test2 failed", "r1 === r2", r1, r2)
  console.assert(r1 === "TAUXX", "test2 failed", "r1 should be equal to 'TAUXX'", r1)
}

function runTests() {
  console.log("Running tests...")

  test1()
  test2()

  console.log("OK All tests passed.")
}

function timed() {
  let a = "TAUXXTAUXXTAUXXTAUXXTAUXX"
  let b = "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"

  console.time("execution time")
  run(a, b)
  console.timeEnd("execution time")
}

runTests()
timed()