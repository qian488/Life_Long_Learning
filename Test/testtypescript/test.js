// 待办事项类
var Todo = /** @class */ (function () {
    function Todo() {
        this.todos = [];
    }
    // 添加待办事项
    Todo.prototype.add = function (todo) {
        this.todos.push(todo);
    };
    // 删除待办事项
    Todo.prototype.remove = function (index) {
        if (index >= 0 && index < this.todos.length) {
            this.todos.splice(index, 1);
        }
    };
    // 显示待办事项列表
    Todo.prototype.display = function () {
        console.log('Todo List:');
        this.todos.forEach(function (todo, index) {
            console.log("".concat(index + 1, ". ").concat(todo));
        });
    };
    return Todo;
}());
// 使用示例
var todoList = new Todo();
todoList.add('Buy groceries');
todoList.add('Do laundry');
todoList.add('Clean the house');
todoList.display();
todoList.remove(1);
todoList.display();
