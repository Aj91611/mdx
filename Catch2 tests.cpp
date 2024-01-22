#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Librarian.h"
#include "Member.h"
#include "Book.h"
#include "Date.h"

TEST_CASE("Test Member class functionality", "[member]") {
    Member member(1, "John Doe", "123 Main St", "john@example.com");

    SECTION("Test Member ID retrieval") {
        REQUIRE(member.getMemberId() == 1);
    }

    SECTION("Test Books Borrowed functionality") {
        member.setBooksBorrowed(101);

        const std::vector<int>& borrowedBooks = member.getBooksBorrowed();

        REQUIRE(borrowedBooks.size() == 1);
        REQUIRE(borrowedBooks[0] == 101);
    }
}

TEST_CASE("Test Librarian class functionality", "[librarian]") {
    Librarian librarian(1001, "Alice Librarian", "456 Library St", "alice@example.com", 50000);

    SECTION("Test Librarian ID retrieval") {
        REQUIRE(librarian.getStaffId() == 1001);
    }

    SECTION("Test Librarian salary retrieval") {
        REQUIRE(librarian.getSalary() == 50000);
    }
}

TEST_CASE("Test Book class functionality", "[book]") {
    Book book(201, "The Catcher in the Rye", "J.D.", "Salinger");

    SECTION("Test Book ID retrieval") {
        REQUIRE(book.getBookId() == 201);
    }

    SECTION("Test Book due date functionality") {
        Date dueDate(2024, 1, 31);
        book.setDueDate(dueDate);

        REQUIRE(book.getDueDate() == dueDate);
    }
}

TEST_CASE("Test Date class functionality", "[date]") {
    Date date1(2023, 12, 15);
    Date date2(2024, 1, 5);

    SECTION("Test Date comparison") {
        REQUIRE(date1 < date2);
    }

    SECTION("Test Date calculation of difference") {
        REQUIRE(date2.calculateDifference(date1) == 21);
    }
}
