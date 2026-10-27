import std;

enum Op : std::uint8_t {

	SET = 0,
	DELETE

};

void execute(std::fstream& db, Op op, const std::string_view key, std::string_view val = "") {
	if (op == SET) {
		db.write("S", sizeof(op));

		std::uint32_t key_len = key.size();
		db.write(reinterpret_cast<const char*>(&key_len), sizeof(key_len));

		db.write(key.data(), key_len);

		std::uint32_t val_len = val.size();
		db.write(reinterpret_cast<const char*>(&val_len), sizeof(val_len));

		db.write(val.data(), val_len);

		db.flush();
	}

	else if (op == DELETE) {
		db.write("D", sizeof(op));

		std::uint32_t key_len = key.size();
		db.write(reinterpret_cast<const char*>(&key_len), sizeof(key_len));

		db.write(key.data(), key_len);
	}
}

int main() {
	std::filesystem::path db_path = "C:/Users/user/Desktop/database.db";

	std::fstream db(db_path, std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);

	if (!db) {
		std::ofstream new_file(db_path);
		db.open(db_path);
	}
	
	execute(db, SET, "Set", "Value");
	execute(db, DELETE, "Set");
}