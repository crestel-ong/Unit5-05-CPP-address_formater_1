// Copyright (c) 2021 Crestel Ong All rights reserved
//
// Created by: Crestel Ong
// Created on: October 2021
// This is the 1st address formater program in C++

#include <iostream>
#include <string>
#include <algorithm>

std::string FormatedAddress(std::string fullName,
        std::string streetNumber, std::string streetName,
        std::string city, std::string province,
        std::string postalCode,
        std::string apartmentNumber = "") {
            // declare
            std::string address;

            // process
            if (apartmentNumber != "") {
                address = (fullName + "\n" + apartmentNumber + "-" +
                streetNumber + " " + streetName + "\n" + city + " " +
                province + " " + postalCode);
            } else {
                address = (fullName + "\n" + streetNumber + " " + streetName
                + "\n" + city +  " " + province + " " + postalCode);
            }
            return address;
        }

main() {
    // get information for mail address
    // name, street number, street name etc.

    // declaring
    std::string fullName;
    std::string apartment;
    std::string apartmentNumber = "";
    std::string streetNumber;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string returnedAddress;

    // Tell the user what this program does
    std::cout << "This program formats your address to a mailing address."
    << std::endl;

    // input
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullName);
    std::cout << "Do you live in an apartment?(y/n): ";
    std::getline(std::cin, apartment);

    if (apartment == "y") {
        std::cout << "Enter your apartment number: ";
        std::getline(std::cin, apartmentNumber); }

    std::cout << "Enter your street number: ";
    std::getline(std::cin, streetNumber);
    std::cout << "Enter your street name AND type (Main St, Express Pkwy…): ";
    std::getline(std::cin, streetName);
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    std::cout << "Enter your province (as abbreviation, ex ON,BC …): ";
    std::getline(std::cin, province);
    std::cout << "Enter your postal code (K2F 8T2): ";
    std::getline(std::cin, postalCode);

    // call functions
    if (apartment == "y") {
        returnedAddress = FormatedAddress(
            fullName,
            streetNumber,
            streetName,
            city,
            province,
            postalCode,
            apartmentNumber);
    } else {
        returnedAddress = FormatedAddress(
            fullName,
            streetNumber,
            streetName,
            city,
            province,
            postalCode);
    }
    // output
    std::cout << "\n";
    std::for_each(returnedAddress.begin(), returnedAddress.end(),
            [](char & c) { c = ::toupper(c);});
    std::cout << returnedAddress << std::endl;
    std::cout << "\nDone.";
}
