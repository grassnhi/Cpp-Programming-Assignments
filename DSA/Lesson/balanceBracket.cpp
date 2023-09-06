bool in_open(char ch){
    string open = "{[(";
    // Scan from left to right
    for(int i = 0; i < open.length(); i++){
        if(open[i] == ch) return true;
    }
    return false;
}

bool in_close(char ch){
    string close = "}])";
    for(int i = 0; i < close.length(); i++){
        if(close[i] == ch) return true;
    }
    return false;
}

bool check_matched(char close_ch, char top){
    string open = "{[(";
    string close = "}])";
    for(int ix = 0; ix < close.length(); ix++){
        if(close_ch == close[ix]){
            char expected = open[ix];
            if(expected == top) return true;
            else  return false;
        }
    }
    return false;
}

bool matched(string expr){
    Stack<char> container;
    for(int idx = 0; idx < expr.length(); idx++){
        char current = expr[idx];
        if(in_open(current)) 
            container.push(current);
        else if(in_close(current)){
            if(container.empty())
                return false;
            else{
                // some char inside of container
                char top = container.pop();
                if(!check_matched(current, top))
                    return false;
            }
        }
    }
    return true; // without any unmatched in expr => matched
}

