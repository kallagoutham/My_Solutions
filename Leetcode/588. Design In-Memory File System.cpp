class Node {
public:
    map<string, Node*> children;
    string content;
    bool isFile;

    Node() {
        content = "";
        isFile = false;
    }
};

class FileSystem {
public:
    Node* root;

    FileSystem() {
        root = new Node();
    }

    vector<string> splitPath(string path) {
        vector<string> parts;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (!token.empty()) {
                parts.push_back(token);
            }
        }

        return parts;
    }

    vector<string> ls(string path) {
        Node* curr = root;
        vector<string> parts = splitPath(path);

        for (string& part : parts) {
            curr = curr->children[part];
        }

        if (curr->isFile) {
            return {parts.back()};
        }

        vector<string> result;

        for (auto& [name, child] : curr->children) {
            result.push_back(name);
        }

        return result;
    }

    void mkdir(string path) {
        Node* curr = root;
        vector<string> parts = splitPath(path);

        for (string& part : parts) {
            if (!curr->children.count(part)) {
                curr->children[part] = new Node();
            }

            curr = curr->children[part];
        }
    }

    void addContentToFile(string filePath, string content) {
        Node* curr = root;
        vector<string> parts = splitPath(filePath);

        for (string& part : parts) {
            if (!curr->children.count(part)) {
                curr->children[part] = new Node();
            }

            curr = curr->children[part];
        }

        curr->isFile = true;
        curr->content += content;
    }

    string readContentFromFile(string filePath) {
        Node* curr = root;
        vector<string> parts = splitPath(filePath);

        for (string& part : parts) {
            curr = curr->children[part];
        }

        return curr->content;
    }
};
