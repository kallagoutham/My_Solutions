/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    var num=init||0;
    var intialNum=init||0;
    this.increment= function(){
        return num+=1;
    }
    this.decrement= function(){
        return num-=1;
    }
    this.reset= function(){
        return num=intialNum;
    }
    return {increment,decrement,reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */
