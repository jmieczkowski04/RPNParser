set(SOURCES
    ConstExpression.cpp
    FunctionExpression.cpp
    MathExpressionOneParam.cpp
    MathExpressionTwoParam.cpp
    RPNParser.cpp
    ParseHelper.cpp
    VarExpression.cpp
)

set(HEADERS
    ConstExpression.h
    Expression.h
    FunctionExpression.h
    MathExpressionOneParam.h
    MathExpressionTwoParam.h
    ParseHelper.h
    VarExpression.h
    Constants.inl
)

add_executable(RPNCalc ${SOURCES} ${HEADERS})

target_include_directories(RPNCalc PRIVATE ${XXHASH_INCLUDE_DIRS})
target_link_libraries(RPNCalc PRIVATE ${XXHASH_LIBRARIES})