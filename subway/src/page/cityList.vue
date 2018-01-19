<template>
  <section class="content">
    <ul>
      <li v-for="city in cityList" v-bind:class="{ select: city.isSelect }" @click="selectCity(city.id)">
        <div class="citySelect">
          {{city.name}}
          <span v-if="city.open">暂未开通</span>
        </div>
      </li>
    </ul>
  </section>
</template>

<script>
export default {
  name: 'cityList',
  data () {
    return {
      cityList: [
        {name: '杭州市', id: 10, open: false, isSelect: false},
        {name: '北京市', id: 11, open: true, isSelect: false},
        {name: '福州市', id: 12, open: true, isSelect: false},
        {name: '数周市', id: 13, open: false, isSelect: false},
        {name: '上海市', id: 14, open: true, isSelect: true},
        {name: '南京市', id: 15, open: false, isSelect: false},
        {name: '苏州市', id: 16, open: true, isSelect: false}
      ]
    }
  },
  methods: {
    selectCity (id) {
      let scope = this
      scope.cityList = scope.cityList.map((item) => {
        if (item.id === id) {
          item.isSelect = true
        } else {
          if (item.isSelect === true) {
            item.isSelect = false
          }
        }
        return item
      })
      scope.$router.push({path: '/cardList'})
    }
  },
  // 页面挂载
  mounted () {

  },
  created () {
    // let scope = this
    document.title = '城市选择'
  }
}
</script>

<style scoped lang='scss'>
  @import '../common/style/variable.scss';
  .content {
    @include fill-all;
    background-color: #fff;
    ul {
      li {
        height: 5rem;
        padding-left:20px;
        .citySelect {
          border-bottom: 1px solid #e7e7e7;
          font-size: 1.8rem;
          color: #333;
          line-height: 5rem;
          span {
            display: block;
            float: right;
            margin-right: 20px;
            color: #999;
          }
        }
        &.select {
          background-color: #f6f8f7;
        }
      }
    }
    
  }
</style>
