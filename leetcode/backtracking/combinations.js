let res = []
function recur(xs, idx, n, k){
    if(k == 0){
        res.push([...xs]);
        return;
    }

    for(let i = idx;i <= n - k + 1; i++){
        xs.push(i);
        recur(xs,  i + 1, n , k - 1  );
        xs.pop();
    }
}

function combine(n, k){
    res = [];
    if(n == k){
        for(let i = 1; i <= n; i++) res.push(i);
        return [res];
    }

    recur([], 1, n, k)
    return res;
}

//console.time("combine");
console.log(combine(2,2))
//console.timeEnd("combine");
 //console.log(res)

