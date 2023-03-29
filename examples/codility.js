/*
    *  for more info watch the video with the title of "Codility SUCKS for SWE Interviews | Prime Reacts"
*/

function solve(S,A){
    return iter(S,A,0,"")
}

function iter(S, A, i = 0, res = ""){
    // If we reach to the 0th person
    if(A[i] === 0 ) return res + S[i]

    //                  K      
    return iter(S, A, A[i], res + S[i])
}

function test(){
    const S0 = "cdeo"
    const A0 = [3,2,0,1]
    console.assert("code" === solve(S0,A0), "should be 'code'")

    const S1 = "cdeenetpi"
    const A1 = [5,2,0,1,6,4,8,3,7]

    console.assert("centipede" === solve(S1, A1), "should be 'centipede'")

    const S2 = "bytdag"
    const A2 = [4,3,0,1,2,5]
    console.assert("bat" ===  solve(S2, A2), "should be 'bat'")
}

test()
