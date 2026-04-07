class Robot {
private:
    int width,height;
    int xc=0,yc=0;
    string currentD = "East";
    unordered_map<string,string> directions;

    // vector<char> directions = {"East","North","West","South"};
public:
    Robot(int width, int height) {
        this->width = width-1;
        this->height = height-1;
        this->directions["East"] = "North";
        this->directions["North"] = "West";
        this->directions["West"] = "South";
        this->directions["South"] = "East";
    }
    
    void step(int num) {
        num = (num % (2*(this->width+this->height)));
        if(num == 0){
            if(this->xc ==0 && this->yc ==0){
                this->currentD = "South";
            }else if(this->xc == this->width && this->yc == this->height){
                this->currentD = "North";
            }else if(this->xc == this->width && this->yc == 0){
                this->currentD = "East";
            }else if(this->xc == 0 && this->yc == this->height ){
                this->currentD = "West";
            }
        }
        while(num--){
            if(this->currentD == "East"){
                if(this->xc == this->width){
                    this->currentD = this->directions[this->currentD];
                    num++;
                }else{
                    this->xc += 1;
                }
            }else if(this->currentD == "West"){
                if(this->xc == 0){
                    this->currentD = this->directions[this->currentD];
                    num++;
                }else{
                    this->xc -= 1;
                }
            }else if(this->currentD == "North"){
                if(this->yc == this->height){
                    this->currentD = this->directions[this->currentD];
                    num++;
                }else{
                    this->yc += 1;
                }
            }else if(this->currentD == "South"){
                if(this->yc == 0){
                    this->currentD = this->directions[this->currentD];
                    num++;
                }else{
                    this->yc -= 1;
                }
            }
        }
    }
    
    vector<int> getPos() {
        return vector<int>{this->xc,this->yc};
    }
    
    string getDir() {
        return this->currentD;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */