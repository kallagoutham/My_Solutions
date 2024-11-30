/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    var num;
    return function() {
        num=(num===undefined)?n:num+1;
        return num;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
