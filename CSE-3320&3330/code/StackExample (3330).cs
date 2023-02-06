public static List<string> ShuntingYard(List<string> expression) {
            List<string> output = new List<string>();
            Stack<string> ops = new Stack<string>();

            string[] operators = { "+", "-", "*", "/", "^", "(", ")" };

            foreach(string token in expression) {
                if (token == "(") {
                    ops.Push(token);
                }

                else if (token == ")") {
                    while(ops.Peek() != "(") {
                        output.Add(ops.Pop());
                    }

                    ops.Pop();
                }

                else if (operators.Contains(token)) {
                    while(ops.Count > 0 && operatorPrescedence(token[0]) < operatorPrescedence(ops.Peek()[0])) {
                        output.Add(ops.Pop());
                    }

                    ops.Push(token);
                }

                else {
                    output.Add(token);
                }
            }

            while(ops.Count > 0) {
                output.Add(ops.Pop());
            }

            return output;
        }