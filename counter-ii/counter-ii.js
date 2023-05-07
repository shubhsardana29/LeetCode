var createCounter = function(init) {
  let currentCount = init;
  return {
    increment: function() {
       return ++currentCount;
    },
    decrement: function() {
       return --currentCount;
    },
    reset: function() {
       currentCount = init;
       return currentCount;
    },
  }
};
