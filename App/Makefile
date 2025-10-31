.PHONY: app clean run check # mấy cái này là lệnh ảo, không phải là file hay thư mục. Mục đích là để tránh trùng tên file hay thư mục

PATH_BUILD := ./build

PATH_OBJ := ./build/obj
PATH_SRC := ./src
PATH_INC := ./inc

#list ra all file trong thư mục src và inc
SRC_FILES := $(wildcard $(PATH_SRC)/*)
INC_FILES := $(wildcard $(PATH_INC)/*)
OBJ_FILES := $(patsubst $(PATH_SRC)/%.cpp, $(PATH_OBJ)/%.o, $(SRC_FILES)) $(PATH_OBJ)/main.o
# tìm tất cả các file .cpp trong thư mục src, sau đó chuyển đổi tên file thành file .o tương ứng trong thư mục obj
# lưu ý đây mới chỉ tạo ra các file .o ảo chứ chưa biên dịch đâu 

CC:=g++
CFLAG:= -I$(PATH_INC)
# CFLAG:= -std=c++17 -Wall -Wextra -I$(PATH_INC)
# Wall (Warn all) : hiện tất cả cảnh báo 
# Wextra : hiện thêm nhiều cảnh báo hơn nữa mà Wall ko hiện

#tạo thư mục nếu nó chưa tồn tại
$(PATH_OBJ): 
	mkdir -p $(PATH_OBJ)

# | $(PATH_OBJ): đây là order-only prerequisite. Trước khi build phải đảm bảo PATH_OBJ tồn tại
# bất kì file .h nào thay đổi make cũng rebuild lại file .o tương ứng
$(PATH_OBJ)/main.o: main.cpp $(INC_FILES) | $(PATH_OBJ)
	$(CC) $(CFLAG) -c $< -o $@

$(PATH_OBJ)/%.o: $(PATH_SRC)/%.cpp $(INC_FILES)
	$(CC) $(CFLAG) -c $< -o $@
# Ở đây dùng $< vì $(PATH_SRC)/%.cpp là 1 prerequisite, ko phải thư mục

check:
	@echo $(SRC_FILES)
	@echo $(INC_FILES)
	@echo $(OBJ_FILES)

# $@ là target (bên trái dấu :)
# $^ là tất cả các prerequisite (bên phải dấu :)
# $< là prerequisite đầu tiên
#Ở đây $^ là tất cả các file .o được liệt kê trong OBJ_FILES
app: $(OBJ_FILES)
	$(CC) $(CFLAG) $^ -o $(PATH_BUILD)/$@

run:
	$(PATH_BUILD)/app

clean:
# 	rm -f $(PATH_OBJ)/*.o $(PATH_BUILD)/app 
	rm -rf $(PATH_BUILD)


