// 待办事项类
class Todo {
    private todos: string[];
  
    constructor() {
      this.todos = [];
    }
  
    // 添加待办事项
    add(todo: string): void {
      this.todos.push(todo);
    }
  
    // 删除待办事项
    remove(index: number): void {
      if (index >= 0 && index < this.todos.length) {
        this.todos.splice(index, 1);
      }
    }
  
    // 显示待办事项列表
    display(): void {
      console.log('Todo List:');
      this.todos.forEach((todo, index) => {
        console.log(`${index + 1}. ${todo}`);
      });
    }
  }
  
  // 使用示例
  const todoList = new Todo();
  todoList.add('Buy groceries');
  todoList.add('Do laundry');
  todoList.add('Clean the house');
  todoList.display();
  
  todoList.remove(1);
  todoList.display();