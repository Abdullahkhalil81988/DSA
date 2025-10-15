td::cout << "\nDepth of nodes:" << std::endl;
    std::cout << "Depth of root (50): " << tree.getDepth(50) << std::endl;   // Should be 0
    std::cout << "Depth of 30: " << tree.getDepth(30) << std::endl;          // Should be 1
    std::cout << "Depth of 20: " << tree.getDepth(20) << std::endl;          // Should be 2
    std::cout << "Depth of non-existent value (100): " << tree.getDepth(100) << std::endl;  // Should be -1

    std::cout << "\nMaximum depth of tree: " << tree.getMaxDepth() << std::endl;  // Should be 2